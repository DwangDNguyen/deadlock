#include<iostream>
#include<thread>
#include<mutex>
#include<time.h>
#include <chrono>
using namespace std::chrono;
using namespace std::literals::chrono_literals;
using namespace std;
std::mutex m1;
std::mutex m2;
void thread1(){
    auto start_a = steady_clock::now();
    clock_t start,end,start_1,end_1,start_2,end_2;
    double time_use;
    double time_m1;
    double time_m2;
    start = clock();
    start_1 = clock();
    m1.lock();
    end_1 = clock();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    start_2 = clock();
    m2.lock();
    end_2 = clock();
    cout<<"Thread 1 duoc thuc hien \n";
    m1.unlock();
    m2.unlock();
    end = clock();
    auto end_a = steady_clock::now();
    time_m1 = (double)(end_1-start_1)/CLOCKS_PER_SEC;
    cout<<" time m1-thred 1 = " << time_m1<<endl;
    time_m2 = (double)(end_2-start_2)/CLOCKS_PER_SEC;
    cout<<" time m2-thred 1 = " << time_m2<<endl;
    time_use = (double)(end-start)/CLOCKS_PER_SEC;
    cout<<" time Thread 1 = " << time_use<<endl;
    auto elapsed1 = duration_cast<duration<int, std::ratio<1, 100000000>>>(end_a - start_a);
    std::cout << "Tong thoi gian Thread 1 = " << elapsed1.count() << " x 10^-8 seconds\n";
}
void thread2(){
    auto start_b = steady_clock::now();
    clock_t start,end,start_1,end_1,start_2,end_2;
    double time_use;
    double time_m1;
    double time_m2;
    start = clock();
    start_1 = clock();
    m1.lock();
    end_1 = clock();
    std::this_thread::sleep_for(std::chrono::seconds(3));
    start_2 = clock();
    m2.lock();
    end_2 = clock();
    cout<<"Thread 2 duoc thuc hien \n";
    m1.unlock();
    m2.unlock();
    end = clock();
    auto end_b = steady_clock::now();
    time_m1 = (double)(end_1-start_1)/CLOCKS_PER_SEC;
    cout<<" time m1-thred 2 = " << time_m1<<endl;
    time_m2 = (double)(end_2-start_2)/CLOCKS_PER_SEC;
    cout<<" time m2-thred 2 = " << time_m2<<endl;
    time_use = (double)(end-start)/CLOCKS_PER_SEC;
    cout<<" time Thread 2 = " << time_use<<endl;
    auto elapsed2 = duration_cast<duration<int, std::ratio<1, 100000000>>>(end_b - start_b);
    std::cout << "Tong thoi gian Thread 2 = " << elapsed2.count() << " x 10^-8 seconds\n";
}
int main(){
    thread t1(thread1);
    thread t2(thread2);
    t1.join();
    t2.join();
}
