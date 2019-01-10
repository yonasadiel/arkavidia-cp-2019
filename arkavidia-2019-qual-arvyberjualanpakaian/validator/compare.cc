#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
#include <cstdarg>
#include <vector>

const int EXIT_AC = 42;
const int EXIT_WA = 43;

std::ifstream judgein, judgeans;
FILE *judgemessage = NULL;
FILE *diffpos = NULL;
int judgeans_pos, stdin_pos;
int judgeans_line, stdin_line;

void wrong_answer(const char *err, ...) {
	va_list pvar;
	va_start(pvar, err);
	fprintf(judgemessage, "Wrong answer on line %d of output (corresponding to line %d in answer file)\n",
			stdin_line, judgeans_line);
	vfprintf(judgemessage, err, pvar);
	fprintf(judgemessage, "\n");
	if (diffpos) {
		fprintf(diffpos, "%d %d", judgeans_pos, stdin_pos);
	}
	exit(EXIT_WA);
}

void judge_error(const char *err, ...) {
	va_list pvar;
	va_start(pvar, err);
	// If judgemessage hasn't been set up yet, write error to stderr
	if (!judgemessage) judgemessage = stderr;
	vfprintf(judgemessage, err, pvar);
	fprintf(judgemessage, "\n");
	assert(!"Judge Error");
}

bool isfloat(const char *s, double &val) {
	char trash[20];
	double v;
	if (sscanf(s, "%lf%10s", &v, trash) != 1) return false;
	val = v;
	return true;
}

template <typename Stream>
void openfile(Stream &stream, const char *file, const char *whoami) {
	stream.open(file);
	if (stream.fail()) {
		judge_error("%s: failed to open %s\n", whoami, file);
	}
}

FILE *openfeedback(const char *feedbackdir, const char *feedback, const char *whoami) {
	std::string path = std::string(feedbackdir) + "/" + std::string(feedback);
	FILE *res = fopen(path.c_str(), "w");
	if (!res) {
		judge_error("%s: failed to open %s for writing", whoami, path.c_str());
	}
	return res;
}

const char *USAGE = "Usage: %s judge_in judge_ans feedback_file [options] < team_out";

int main(int argc, char **argv) {
	if(argc < 4) {
		judge_error(USAGE, argv[0]);
	}
	judgemessage = openfeedback(argv[3], "judgemessage.txt", argv[0]);
	diffpos = openfeedback(argv[3], "diffposition.txt", argv[0]);
	openfile(judgein, argv[1], argv[0]);
	openfile(judgeans, argv[2], argv[0]);


	judgeans_pos = stdin_pos;
	judgeans_line = stdin_line = 1;

	// start of custom validator

    int t, n, k, x, m_team, m_judge;
    std::vector<int> judge;
    std::vector<int> team;

    judgein >> t;
    for (int tc=1; tc<=t; tc++) {
        judgein >> n >> k;
        for (int i=0; i<n; i++) {
            judgein >> x;
        }
        judge.clear();
        team.clear();
        if (!(std::cin >> m_team)) wrong_answer("Unexpected EOF");
        for (int i=0; i<m_team; i++) {
            if (!(std::cin >> x)) wrong_answer("Unexpected EOF");
            team.push_back(x);
        }
        judgeans >> m_judge;
        for (int i=0; i<m_judge; i++) {
            judgeans >> x;
            judge.push_back(x);
        }

        sort(judge.begin(), judge.end());
        sort(team.begin(), team.end());
        if (m_judge != m_team) {
            char err[200];
            sprintf(err, "TC #%d judge has m = %d but team has m = %d", tc, m_judge, m_team);
            wrong_answer(err);
        }
        for (int i=0; i<m_judge; i++) {
            if (judge[i] != team[i]) {
                char err[200];
                sprintf(err, "TC #%d judge answer differ from team in %d-th number", tc, i + 1);
                wrong_answer(err);
            }
        }

    }
    exit(EXIT_AC);
}