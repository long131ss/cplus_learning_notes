#include <boost/asio/io_service.hpp>
#include <thread>
#include <iostream>

void task1()
{
    std::cout << "Task 1 is running." << std::endl;
}

void task2()
{
    std::cout << "Task 2 is running." << std::endl;
}

int main()
{
    boost::asio::io_service io_service;
    boost::asio::io_service::work work(io_service);

    std::thread thread1([&io_service]() {
        io_service.run();
    });

    std::thread thread2([&io_service]() {
        io_service.run();
    });

    io_service.post(task1);
    io_service.post(task2);

    thread1.join();
    thread2.join();

    return 0;
}
