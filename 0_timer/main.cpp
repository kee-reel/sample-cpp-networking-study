#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>

void print(const boost::system::error_code &e, boost::asio::steady_timer* t, int* count)
{
    std::cout << "Async call" << std::endl;
    if (!*count)
        return;
    std::cout << *count << std::endl;
    --(*count);
    t->expires_at(t->expiry() + boost::asio::chrono::seconds(1));
    t->async_wait(boost::bind(&print, boost::asio::placeholders::error, t, count));
}

int main()
{
    boost::asio::io_context io;
    boost::asio::steady_timer t(io, boost::asio::chrono::seconds(1));
    std::cout << "Waiting for 5 secounds..." << std::endl;
    //t.wait();
    int i = 5;
    t.async_wait(boost::bind(&print, boost::asio::placeholders::error, &t, &i));
    // If no parameters:
    // t.async_wait(&print);
    // Skips if there is no work, waits if there is some:
    io.run();
    std::cout << "Done" << std::endl;
}
