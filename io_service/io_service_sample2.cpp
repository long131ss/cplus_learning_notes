#include <boost/asio/io_context.hpp>
#include <boost/asio/executor_work_guard.hpp>
#include <iostream>
#include <thread>

int main()
{
    boost::asio::io_context io_context;
    
    // Create a work guard to keep the io_context active
    boost::asio::executor_work_guard<boost::asio::io_context::executor_type> work_guard(io_context.get_executor());
    
    // Use io_context for asynchronous operations
    io_context.post([](){
        std::cout << "Hello, world!" << std::endl;
        std::cout << "io_context:" << std::this_thread::get_id() << std::endl;
    });
    
    // Run the io_context to start event processing
    std::cout << "main:" << std::this_thread::get_id() << std::endl;
    io_context.run();
    std::cout << "finished" << std::endl;
    return 0;
}

