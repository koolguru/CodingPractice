#include <vector>
#include <string>
#include <iostream>

using namespace std;
vector<string> fizzBuzz(int n) {
        vector<string> fizzBuzz;
        for(int i = 1; i < n; i++)
        {
            if(i%3 == 0 && i%5 == 0)
            {
                cout << "fizzbuzz" << endl;
                fizzBuzz.push_back("FizzBuzz");
            }
            else if(i%5 == 0)
            {
                cout << "buzz" << endl;
                fizzBuzz.push_back("Buzz");
            }
            else if(i%3 == 0)
            {
                cout << "fizz" << endl;
                fizzBuzz.push_back("Fizz");
            }
            else
            {
                cout << i << endl;
                fizzBuzz.push_back(to_string(i));
            }
        }
        return fizzBuzz;
    }

int main()
{
	vector<string> fizz = fizzBuzz(10);
  for(int i = 0; i < 10; i++)
  {
    cout << fizz.at(i) << endl;
  }
}
