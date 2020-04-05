#pragma once
#include "System/Export.h"
#include <vector>
#include <string>
#include <queue>

namespace mt
{
	class NDMTENGINE_API Score
	{
	private:
		wchar_t* m_sUser = nullptr;
		int m_nScore = 0;

	public:
		Score();
		Score(const wchar_t* user, int score);
		Score(const Score& score);
		~Score();

		void setUser(const wchar_t* user);
		const wchar_t* getUser() const;

		void setScore(int score);
		int getScore() const;

		static Score getMaxScore(std::wstring linkScore);
		static std::vector<Score> getTopScore(int top, std::wstring linkScore);
		bool Save(const wchar_t* linkScore);

		Score operator=(const Score& score);
		Score operator++();
		Score operator++(int);
		Score operator--();
		Score operator--(int);
		Score operator+(int score);
		Score operator-(int score);

	protected:
		bool getOneUser(FILE* f);
	};

	bool operator>(const Score& s1, const Score& s2);
	bool operator<(const Score& s1, const Score& s2);
}
