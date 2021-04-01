#include <iostream>

using namespace std;

void finalFunc (int happiness, int money, int health) {
  if (happiness == 2 && money == 2 && health == 2) {
    cout << "Congratulations, you lived your best teenage life!" << endl;
  }
  else if (happiness == 1 && money == 1 && health == 1) {
    cout << "Hmm.. Not too bad! You lived a pretty decent teenage life!" << endl;
  }
  else if (happiness == 0 && money == 0 && health == 0) {
    cout << "How do you mess up that bad??" << endl;
  }
  else if (happiness == 2 && money == 0 && health == 0) {
    cout << "You're broke and unhealthy.. but at least you had fun, right?" << endl;
  }
  else if (happiness == 0 && money == 2 && health == 0) {
    cout << "You're rich, but is it worth the sacrifices? (yes it was)" << endl;
  }
  else {
    cout << "You lived a.. pretty normal teenage life, I guess?" << endl;
  }
}
