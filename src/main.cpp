#include <iostream>

#include "commun.h"

#include "system.h"
#include "window.h"
#include "input.h"
#include "time.h"

int main(int argc,char* argv[])
{

	system::init();
	

	while(!window::get_current().lock()->get_close())
	{	
		double t0 = time::get_time();

		time::update();		
		system::event();
		input::update();

		system::update();
		
		system::draw();
		
		window::get_current().lock()->swap_buffer();

		while((17.0 - (time::get_time()-t0))>0.0);
	}
	

	window::get_current().lock()->term();

	system::term();

	return 0;
}