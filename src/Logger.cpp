#include "Logger.h"
#include "ShapeWithVertices.h"
#include <algorithm>
#include <chrono>
#include <fmt/format.h>
#include <sstream>

Logger::Logger(const std::string &fileName,
               std::chrono::milliseconds flushInterval)
    : flushInterval(flushInterval) {

  logger = spdlog::basic_logger_mt("basic_logger", fileName);
  spdlog::set_pattern("%Y-%m-%d %H:%M:%S %z [%^%l%$] %v");

  messages.reserve(1000);

  loggingThread = std::thread(&Logger::flushLogs, this);
}

Logger::~Logger() {
  running = false;
  if (loggingThread.joinable()) {
    loggingThread.join();
  }
}

void Logger::logShape(const ShapeWithVertices &shape) {
  auto vertices = shape.getVertices();

  std::ostringstream logStream;
  std::for_each(vertices.begin(), vertices.end(),
                [&logStream, idx = 0](const auto &vertice) mutable {
                  logStream << fmt::format("\nVertice {}: ({}, {}, {})", idx,
                                           vertice.x, vertice.y, vertice.z);
                  idx++;
                });

  std::string strLog = logStream.str() + '\n';

  log(strLog);
}

void Logger::log(const std::string &message) {
  std::lock_guard<std::mutex> lock(std::mutex);
  messages.push_back(message);
}

void Logger::flushLogs() {
  while (running) {
    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::lock_guard<std::mutex> lock(mutex);
    std::for_each(messages.begin(), messages.end(),
                  [this](const auto &message) { logger->info(message); });
    messages.clear();
  }
}
