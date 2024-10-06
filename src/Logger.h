#ifndef INCLUDE_SRC_LOGGER_H_
#define INCLUDE_SRC_LOGGER_H_

#include "ShapeWithVertices.h"
#include <chrono>
#include <mutex>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/spdlog.h>
#include <string>
#include <thread>
#include <vector>

class Logger {
public:
  Logger(const std::string &fileName, std::chrono::milliseconds flushInterval);
  ~Logger();

  void logShape(const ShapeWithVertices &shape);

private:
  void log(const std::string &message);
  void flushLogs();

  std::chrono::milliseconds flushInterval;
  std::vector<std::string> messages;
  std::mutex mutex;
  std::thread loggingThread;
  std::shared_ptr<spdlog::logger> logger;
  bool running = true;
};

#endif // INCLUDE_SRC_LOGGER_H_
