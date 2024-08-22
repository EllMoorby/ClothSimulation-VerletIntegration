#include "application.h"


Application::Application() {

}

void Application::start() {
	generatePoints(3);
	createWindow();
	while (window.isOpen()) {
		update();
	}
	destroyWindow();
}

void Application::generatePoints(unsigned int numPoints) {
	/*float spacing = Settings::ScreenWidth / numPoints;
	for (int i = 0; i < numPoints; i++) {
		PointMass newPoint;
		std::cout << spacing * i + 100.f;
		newPoint.createPoint(spacing * i+100.f, 100.f, 10, false);
		points.push_back(newPoint);
	}*/

	PointMass p1;
	PointMass p2;
	PointMass p3;

	p1.createPoint(Settings::ScreenWidth/2, 100, 10, true);
	p2.createPoint(200, 100, 10, false);
	p3.createPoint(300, 100, 10, false);

	points.push_back(p1);
	points.push_back(p2);
	points.push_back(p3);

	Link p1p2(points[0], points[1], 150.f, 10.f, 0.f);
	//Link p2p3(points[1], points[2], 150.f, 10.f, 0.f);

	links.push_back(p1p2);
	//links.push_back(p2p3);
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
		case sf::Event::MouseButtonPressed:
			switch (event.mouseButton.button) {
			case sf::Mouse::Left:
				mousePosition = sf::Mouse::getPosition(window);
				createPoint(mousePosition.x, mousePosition.y, 10, false);
				break;
			case sf::Mouse::Right:
				mousePosition = sf::Mouse::getPosition(window);
				createPoint(mousePosition.x, mousePosition.y, 10, true);
				break;
			}
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
	timesteps = floor(elapsedTime / 16);

	// store time we couldn't use for the next frame.
	leftOverTime = elapsedTime - timesteps * 16;
	for (int i = 0; i < timesteps; i++) {
		for (PointMass& point : points) {
			point.update(window);
			
		}
		for (Link& link : links) {
			link.solve();
		}
		
		window.display();
		window.clear();
	}
	

	
}

void Application::createPoint(float x, float y, unsigned int radius, bool pinned) {
	PointMass newPoint;
	newPoint.createPoint(x, y, radius, pinned);
	points.push_back(newPoint);
}

void Application::destroyWindow() {
	window.close();
}
