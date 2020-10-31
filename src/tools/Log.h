#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/fmt/ostr.h>

namespace Fractal 
{
	class Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetLogger() { return s_Logger; }

	private:
		static std::shared_ptr<spdlog::logger> s_Logger;
	};
}

// LOGGING ENABLED
#define LOG_TRACE(...)   ::Fractal::Log::GetLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...)    ::Fractal::Log::GetLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)    ::Fractal::Log::GetLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)   ::Fractal::Log::GetLogger()->error(__VA_ARGS__)
#define LOG_FATAL(...)   ::Fractal::Log::GetLogger()->fatal(__VA_ARGS__)

// LOGGING DISABLED
// #define LOG_TRACE   
// #define LOG_INFO   
// #define LOG_WARN 
// #define LOG_ERROR
// #define LOG_FATAL 



