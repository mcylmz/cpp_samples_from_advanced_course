#include <thread>
#include <iostream>
#include <chrono>
#include <syncstream>

int main()
{
    using namespace std;

    jthread t1{
      [](stop_token stoken) {
          while(!stoken.stop_requested()) {
              cout.put("*");
              this_thread::sleep_for(10ms)
          }
      }
    };

    jthread t2{
      [](stop_token stoken) {
          while(!stoken.stop_requested()) {
              cout.put(".");
              this_thread::sleep_for(10ms)
          }
      }
    };

    this_thread::sleep_for(10ms);
    osyncstream{ cout } << "\nSending stop request...\n";
    t1.request_stop();
    t2.request_stop();
    cout << "Stopped\n";
}
