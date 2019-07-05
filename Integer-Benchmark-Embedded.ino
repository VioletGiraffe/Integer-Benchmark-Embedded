#include <Arduino.h>

#include <stdint.h>
#include <utility>

inline uint16_t fast_sqrt32(uint32_t x)
{
	uint16_t res = 0;
	uint16_t add = static_cast<uint16_t>(0x8000U);

	for (int i = 0; i < 16; i++)
	{
		const uint16_t temp = res | add;
		const uint32_t g2 = static_cast<uint32_t>(temp) * static_cast<uint32_t>(temp);
		if (x >= g2)
			res = temp;

		add >>= 1;
	}

	return res;
}

template <int N, bool usePreviouslyFoundValues>
std::pair<unsigned long /* time */, uint32_t /* checksum */> findPrimes()
{
	const auto start = millis();
		uint32_t checksum = 0;
	int found = 0;
	for (uint32_t i = 3; ; i += 2)
	{
		bool prime = true;
		for (uint16_t divisor = 3, square_root = fast_sqrt32(i); divisor <= square_root; divisor += 2)
		{
			if (i % divisor == 0)
			{
				prime = false;
				break;
			}
		}

		if (prime)
		{
			checksum += i;
			if (++found >= N)
				break;
		}
	}

	return std::make_pair(millis() - start, checksum);
}

void setup()
{
	Serial.begin(115200);

	Serial.println("Calculating...");
	constexpr int N = 2500;
	const auto result = findPrimes<N, false>();

	Serial.print("Time, milliseconds: "); Serial.println(result.first);
	Serial.print("Checksum: "); Serial.println(result.second);
}

void loop() {}