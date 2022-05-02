#include "manager.h"
#include "mediaContainer.h"
#include "patronList.h"

using namespace std;

int main() {
    Manager manager;
    manager.inputMediaFile("data4books.txt");
    manager.inputPatronFile("data4patrons.txt");
    manager.inputCommandFile("data4commands.txt");
}