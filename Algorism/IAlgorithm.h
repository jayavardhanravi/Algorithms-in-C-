#ifndef IALGORITHM_H
#define IALGORITHM_H

#include <iostream>
#include <memory>
#include <chrono>

namespace algo
{
	// Parent class of all algorithm classes created in this project
	template<typename ALGORITHM>
	class IAlgorithm
	{
	public:
		IAlgorithm() {};
		IAlgorithm(const IAlgorithm&) = delete;
		IAlgorithm& operator= (const IAlgorithm&) = delete;
		virtual ~IAlgorithm() {};

		static std::shared_ptr<ALGORITHM> getInstance()
		{
			static std::shared_ptr<ALGORITHM> m_instance;
			if(!m_instance)
				m_instance = std::make_shared<ALGORITHM>();
			return m_instance;
		};
		virtual void printProblemStatement() {};
		virtual void input() {};
		virtual void process() {};
		virtual void output() {};

		static void execute()
		{
			getInstance()->printProblemStatement();
			getInstance()->input();
			getInstance()->process();
			getInstance()->output();
		};

		enum class TIMER{
			START = 0x101,
			END = 0x102,
			PRINT = 0x103
		};

		typedef std::chrono::milliseconds MILLI;
		typedef std::chrono::microseconds MICRO;
		typedef std::chrono::nanoseconds NANO;

	protected:
		std::chrono::high_resolution_clock::time_point startTimer, endTimer;
		template<typename TIME_UNITS>
		long long processTimer(TIMER time)
		{
			switch (time)
			{
			case TIMER::START:
			{
				startTimer = std::chrono::high_resolution_clock::now();
				return std::chrono::duration_cast<TIME_UNITS>(startTimer.time_since_epoch()).count();
			}
			case TIMER::END:
			{
				endTimer = std::chrono::high_resolution_clock::now();
				return std::chrono::duration_cast<TIME_UNITS>(endTimer.time_since_epoch()).count();
			}
			case TIMER::PRINT:
			{
				return std::chrono::duration_cast<TIME_UNITS>(endTimer - startTimer).count();
			}
			default:
				break;
			}
			return -1;
		};
	};
} // namespace algo

#endif // IALGORITHM_H

