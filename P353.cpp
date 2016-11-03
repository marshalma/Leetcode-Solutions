#include "Header.hpp"
#include <utility>

using namespace std;

class SnakeGame {
	int width;
	int height;
	int foodpos;
	vector<pair<int, int>> food;
	deque<pair<int, int>> body;
	unordered_set<string> body_hash;
	
	string make_string(pair<int, int> p) {
		return to_string(p.first) + "_" + to_string(p.second);
	}
	
public:
	/** Initialize your data structure here.
		@param width - screen width
		@param height - screen height 
		@param food - A list of food positions
		E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
	SnakeGame(int width, int height, vector<pair<int, int>> food): width(width), height(height), food(food) {
		body.push_back(make_pair(0, 0));
		body_hash.insert(make_string(make_pair(0, 0)));
		foodpos = 0;
	}
	
	/** Moves the snake.
		@param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
		@return The game's score after the move. Return -1 if game over. 
		Game over when snake crosses the screen boundary or bites its body. */
	int move(string direction) {
		pair<int, int> head = body.back();
		pair<int, int> next;
		
		// remove tail
		auto tail = body.front();
		body_hash.erase(make_string(tail));
		body.pop_front();
		
		// find potential next head
		if (direction == "U") {next.first = head.first-1; next.second = head.second;}
		else if (direction == "D") {next.first = head.first+1; next.second = head.second;}
		else if (direction == "L") {next.first = head.first; next.second = head.second-1;}
		else {next.first = head.first; next.second = head.second+1;}
		
		//
		if (next.first < 0 || next.second < 0 || next.first == height || next.second == width) return -1;
		else if (body_hash.find(make_string(next)) != body_hash.end()) return -1;
		else if (food[foodpos] == next) {
			foodpos++;
			body.push_back(next);
			body_hash.insert(make_string(next));
			return foodpos;
		}
		else {
			body.push_front(tail);
			body.push_back(next);
			body_hash.insert(make_string(next));
			body_hash.insert(make_string(tail));
			return 0;
		}
	}
};