#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>

typedef enum e_LoggerVerbosityLevel {
    kLoggerVerbosityDisabled = 0,
    kLoggerVerbosityFatal = 1,
    kLoggerVerbosityError = 2,
    kLoggerVerbosityWarning = 3,
    kLoggerVerbosityInfo = 4,
    kLoggerVerbosityDebug = 5,
    kLoggerVerbosityTrace = 6
} LoggerVerbosityLevel;

class Logger
{
public:
    static void setVerbosityLevel(LoggerVerbosityLevel verbosityLevel);
    static void setVerbosityLevel(char verbosityLevel);
    static bool shouldPrint(LoggerVerbosityLevel verbosityLevel);

public:
    static LoggerVerbosityLevel verbosityLevel;
};

#define LOG_TRACE(expression) if (Logger::shouldPrint(kLoggerVerbosityTrace)) { std::cout << "TRACE: " << expression << std::endl; }
#define LOG_DEBUG(expression) if (Logger::shouldPrint(kLoggerVerbosityDebug)) { std::cout << "DEBUG: " << expression << std::endl; }
#define LOG_INFO(expression) if (Logger::shouldPrint(kLoggerVerbosityInfo)) { std::cout << "INFO: " << expression << std::endl; }
#define LOG_WARN(expression) if (Logger::shouldPrint(kLoggerVerbosityWarning)) { std::cout << "WARN: " << expression << std::endl; }
#define LOG_ERROR(expression) if (Logger::shouldPrint(kLoggerVerbosityError)) { std::cout << "ERROR: " << expression << std::endl; }
#define LOG_FATAL(expression) if (Logger::shouldPrint(kLoggerVerbosityFatal)) { std::cout << "FATAL: " << expression << std::endl; }

#endif // LOGGER_H
