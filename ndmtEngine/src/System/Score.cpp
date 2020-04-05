#include "pch.h"
#include "System/Score.h"

namespace mt
{
	Score::Score() : m_sUser(nullptr), m_nScore(0)
	{
		
	}

	Score::Score(const wchar_t* user, int score)
	{
		setUser(user);
		m_nScore = score;
	}

	Score::Score(const Score& score)
	{
		setUser(score.m_sUser);
		m_nScore = score.m_nScore;
	}

	Score::~Score()
	{
		if (m_sUser != nullptr)
			delete[] m_sUser;
		m_sUser = nullptr;
	}

	void Score::setUser(const wchar_t* user)
	{
		if (user == nullptr)
			return;

		if (m_sUser != nullptr)
		{
			delete[] m_sUser;
			m_sUser = nullptr;
		}

		int len = wcslen(user);
		m_sUser = new wchar_t[len + 1];
		wcscpy_s(m_sUser, len + 1, user);
	}

	const wchar_t* Score::getUser() const
	{
		return m_sUser;
	}

	void Score::setScore(int score)
	{
		m_nScore = score;
	}

	int Score::getScore() const
	{
		return m_nScore;
	}

	Score Score::getMaxScore(std::wstring linkScore)
	{
		std::vector<Score> vct = getTopScore(1, linkScore);

		if (vct.size() != 0)
			return vct[0];

		return Score();
	}

	std::vector<Score> Score::getTopScore(int top, std::wstring linkScore)
	{
		FILE* f = nullptr;
		_wfopen_s(&f, linkScore.c_str(), L"rb");

		if (f == nullptr)
			return std::vector<Score>();

		std::priority_queue<Score, std::vector<Score>, std::greater<Score>> queue;

		while (true)
		{
			Score score;
			if (!score.getOneUser(f))
				break;

			queue.push(score);

			if (queue.size() > top)
				queue.pop();
		}

		std::vector<Score> vctScore(queue.size());
		for (int i = 0; i < vctScore.size(); i++)
		{
			vctScore[i] = queue.top();
			queue.pop();
		}

		fclose(f);
		return vctScore;
	}

	bool Score::Save(const wchar_t* linkScore)
	{
		if (m_sUser == nullptr)
			setUser(L"");

		int nLength = wcslen(m_sUser);

		FILE* f = nullptr;
		_wfopen_s(&f, linkScore, L"ab");

		if (f == nullptr)
			return false;

		fwrite(&nLength, sizeof(int), 1, f);
		fwrite(m_sUser, sizeof(wchar_t), nLength, f);
		fwrite(&m_nScore, sizeof(int), 1, f);

		fclose(f);
		return true;
	}

	Score Score::operator=(const Score& score)
	{
		setUser(score.m_sUser);
		m_nScore = score.m_nScore;

		return *this;
	}

	Score Score::operator++()
	{
		operator+(1);
		return *this;
	}

	Score Score::operator++(int)
	{
		Score score = *this;
		operator+(1);
		return score;
	}

	Score Score::operator--()
	{
		operator-(1);
		return *this;
	}

	Score Score::operator--(int)
	{
		Score score = *this;
		operator-(1);
		return score;
	}

	Score Score::operator+(int score)
	{
		m_nScore += score;
		return *this;
	}

	Score Score::operator-(int score)
	{
		m_nScore -= score;
		return *this;
	}

	bool Score::getOneUser(FILE* f)
	{
		if (m_sUser != nullptr)
			delete m_sUser;

		int nLength = 0;
		if (fread(&nLength, sizeof(int), 1, f) != 1)
			return false;

		m_sUser = new wchar_t[nLength + 1];
		if (fread(m_sUser, sizeof(wchar_t), nLength, f) != nLength)
			return false;
		m_sUser[nLength] = L'\0';

		fread(&m_nScore, sizeof(int), 1, f);

		return true;
	}

	bool operator<(const Score& s1, const Score& s2)
	{
		if (s1.getScore() < s2.getScore())
			return true;
		return false;
	}

	bool operator>(const Score& s1, const Score& s2)
	{
		if (s1.getScore() > s2.getScore())
			return true;
		return false;
	}
}