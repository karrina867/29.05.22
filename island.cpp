#include"islands.h"
#include"const.h"
std::string Islands::islands_file_names[] = {
	ISLAND_1,
	ISLAND_2,
	ISLAND_3,
	ISLAND_4,
};
Islands::Islands() {
	size_t nu = rand() % ISLANDS_TYPE_QTY;
	texture.loadFromFile(IMAGES_FOLDER + islands_file_names[nu]);
	sprite.setTexture(texture);
	spawn();
}
void Islands::update() {
	sprite.move(speedx, speedy);
	sf::FloatRect g_bound = sprite.getGlobalBounds();
	if (sprite.getPosition().x < 0 - g_bound.width ||
		sprite.getPosition().x > WINDOW_WIDTH ||
		sprite.getPosition().y > WINDOW_HEIGHT)
	{
		spawn();
	}
}
void Islands::draw(sf::RenderWindow& window) { window.draw(sprite); }
void Islands::spawn() {
	sf::FloatRect g_bound = sprite.getGlobalBounds();
	float x = rand() % (static_cast<size_t>(2));
	float y = rand() % (static_cast<size_t>(WINDOW_HEIGHT)) - WINDOW_HEIGHT-100;
	sprite.setPosition(x, y);
	speedx = 0;
	speedy = 4;
}
sf::FloatRect Islands::getHitBox() { return sprite.getGlobalBounds(); }
sf::Vector2f Islands::getPosition() { return sprite.getPosition(); }