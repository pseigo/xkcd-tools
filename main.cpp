#include <cstdlib>      // srand, rand
#include <ctime>        // time
#include <iostream>
#include <vector>

using namespace std;

void wait(int);
void generate(const vector<string>&, const vector<string>&, const vector<string>&);

int main()
{
    const vector<string> verbs = {
        "make",
        "monitor",
        "deploy",
        "build",
        "test",
        "develop",
        "run",
        "compile",
    };

    const vector<string> participles = {
        "making",
        "monitoring",
        "deploying",
        "building",
        "testing",
        "developing",
        "running",
        "compiling",
    };

    const vector<string> nouns = {
        "tools",
        "code",
        "monitors"
    };

    const unsigned iterations = 20;	// # of phrases to generate
    const unsigned delay = 1000;	// in milliseconds

    srand( unsigned(time(0)) );

    cout << "Cueball: What do you do?\n\n";
    cout << "Megan: I make tools" << flush;

    for (int i = 0; i != iterations; ++i) {
        cout << ' ';
        generate(verbs, participles, nouns);

        wait(delay);
    }

    cout << ".\n\n";
    cout << "Cueball: But what's it all *for*?\n";
    cout << "Megan: Honestly, no idea. Porn, probably.\n\n";

    cout << "based on xkcd comic #1629: \"Tools\". https://xkcd.com/1629/" << endl;

    return 0;
}

// TODO use something efficient
void wait(int time)
{
    const long referenceTime = clock() + time; // in milliseconds

    while (referenceTime - clock() > 0);
    cout << flush;
}

void generate(const vector<string>& verbs,
    const vector<string>& participles,
    const vector<string>& nouns)
{
    const bool verb = rand() % 2;
    const auto nounIndex = rand() % nouns.size();

    if (verb) {
        const auto verbIndex = rand() % verbs.size();
        const bool makePlural = rand() % 2;

        cout << "that " << verbs[verbIndex];

        if (makePlural) {
            cout << 's';
        }

        cout << ' ' << nouns[nounIndex];
    } else {
        const auto participleIndex = rand() % participles.size();

        cout << "for " << participles[participleIndex]
             << ' ' << nouns[nounIndex];
    }
}
