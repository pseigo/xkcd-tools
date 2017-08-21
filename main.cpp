#include <iostream>
#include <cstdlib>      // srand, rand
#include <ctime>        // time
#include <vector>

using namespace std;

void wait(int);
void generate(const vector<string>&, const vector<string>&, const vector<string>&);

int main()
{
    // TODO get words from a file or something because this is a MESS
    vector<string> verbs = {
        "make",
        "monitor",
        "deploy",
        "build",
        "test",
        "develop",
        "run",
        "compile",
    };

    vector<string> participles = {
        "making",
        "monitoring",
        "deploying",
        "building",
        "testing",
        "developing",
        "running",
        "compiling",
    };

    vector<string> nouns = {
        "tools",
        "code",
        "monitors"
    };

    srand( unsigned(time(0)) );
    unsigned iterations = 20;	// how many layers are there to this onion?
    unsigned delay = 1000;	// milliseconds

    cout << "Cueball: What do you do?\n\n";
    cout << "Megan: I make tools" << flush;

    for (int i = 0; i != 20; ++i) {
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
    long referenceTime = clock() + time; // in ms

    while (referenceTime - clock() > 0);
    cout << flush;
}

void generate(const vector<string>& verbs,
    const vector<string>& participles,
    const vector<string>& nouns)
{
    // START LOOP
    bool verb = rand() % 2;
    auto nounIndex = rand() % nouns.size();

    // rand % (max - min + 1) + min
    // rand % (verbs.size() + 1)
    if (verb) {
        auto verbIndex = rand() % verbs.size();
        bool makePlural = rand() % 2;

        cout << "that " << verbs[verbIndex];
        if (makePlural)
            cout << 's';
        cout << ' ' << nouns[nounIndex];

    } else {
        auto participleIndex = rand() % participles.size();

        cout << "for " << participles[participleIndex]
             << ' ' << nouns[nounIndex];
    }
}
