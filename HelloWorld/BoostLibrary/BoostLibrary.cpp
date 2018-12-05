#include "pch.h"
#include <iostream>
#include <boost/asio.hpp>

int main()
{
	boost::asio::io_context io;

	boost::asio::steady_timer timer = boost::asio::steady_timer(io, boost::asio::chrono::seconds(3));

    std::cout << "Start\n"; 

	timer.wait();

	io.run();

	std::cout << "Stop\n";

	return 0;
}

