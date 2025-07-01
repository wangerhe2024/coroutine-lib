#include "thread.h"
#include <iostream>
#include <memory>
#include <unistd.h>
#include <vector>

using namespace ww_coroutine;

void func() {
  std::cout << "id: " << Thread::GetThreadId()
            << ", name: " << Thread::GetName();
  std::cout << ", this id: " << Thread::GetThis()->getId()
            << ", this name: " << Thread::GetThis()->getName() << std::endl;

  sleep(60);
}

int main() {
  std::vector<std::shared_ptr<Thread>> thrs;

  for (int i = 0; i < 5; i++) {
    std::shared_ptr<Thread> thr =
        std::make_shared<Thread>(&func, "thread_" + std::to_string(i));
    thrs.push_back(thr);
  }

  for (int i = 0; i < 5; i++) {
    thrs[i]->join();
  }

  return 0;
}