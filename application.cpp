#include "application.h"


Application::Application(unsigned int screenHeight, unsigned int screenWidth, unsigned int fps) {
	this->screenHeight = screenHeight;
	this->screenWidth = screenWidth;
	this->fps = fps;
}

void Application::start() {
	createWindow();
	while (window.isOpen()) {
		update();
	}
	destroyWindow();
}

void Application::createWindow() {
	window.create(sf::VideoMode(screenWidth, screenHeight), "ClothSimulation", sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(fps);
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

	window.clear();

	//draw

	window.display();
}

void Application::destroyWindow() {
	window.close();
}
