#include "application.h"


Application::Application() {

}

void Application::start() {
	point.createPoint(100, 100, 10);
	createWindow();
	while (window.isOpen()) {
		update();
	}
	destroyWindow();
}

void Application::createWindow() {
	window.create(sf::VideoMode(Settings::ScreenWidth, Settings::ScreenHeight), "ClothSimulation", sf::Style::Titlebar | sf::Style::Close);
}

void Application::update() {
	while (window.pollEvent(event))
	{
		switch (event.type) {
		case sf::Event::Closed:
			window.close();
			break;
		}
	}

	currentTime = clock.getElapsedTime();

	//Time since last frame
	elapsedTime = (currentTime - lastTime).asMicroseconds() / (1000.f);

	lastTime = currentTime; // reset lastTime
	
	// add time that couldn't be used last frame
	elapsedTime += leftOverTime;

	// divide it up in chunks of 16 ms
	int timesteps = floor(elapsedTime / 16);
	

	// store time we couldn't use for the next frame.
	leftOverTime = elapsedTime - timesteps * 16;
	
	
	point.update(timesteps);

	window.clear();

	window.draw(point.getBody());

	window.display();
}

void Application::destroyWindow() {
	window.close();
}
