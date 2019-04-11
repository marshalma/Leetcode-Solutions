#include "Header.hpp"

using namespace std;

class Twitter {
	struct Comp2 {
		bool operator() (const pair<int, int> &a, const pair<int, int> &b) {
			return a.first > b.first;
		}
	};
	
	struct Comp {
		bool operator() (const pair<int, set<pair<int, int>, Comp2>::iterator> &a, const pair<int, set<pair<int, int>, Comp2>::iterator> &b) const {
			return (*a.second).first > (*b.second).first;
		}
	};
	
	using set_pair = set<pair<int, int>, Comp2>; // <time_stamp, content>
	using iter_pair = pair<int, set_pair::iterator>;
	
	int time_stamp;
	unordered_map<int, unordered_set<int>> user_relation;
	unordered_map<int, set_pair> user_posts;
	
public:
	/** Initialize your data structure here. */
	Twitter() {
		time_stamp = 0;
	}
	
	/** Compose a new tweet. */
	void postTweet(int userId, int tweetId) {
		user_posts[userId].insert(make_pair(time_stamp, tweetId));
	}
	
	/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
	vector<int> getNewsFeed(int userId) {
		priority_queue<iter_pair, vector<iter_pair>, Comp> pq;
		if (user_posts[userId].size() > 0) pq.push(make_pair(userId, user_posts[userId].begin()));
		for (const auto user : user_relation[userId]) {
			if (user_posts[user].size() > 0) pq.push(make_pair(user, user_posts[user].begin()));
		}
		vector<int> res;
		while (res.size() < 10 && !pq.empty()) {
			auto user_pair = pq.top();
			pq.pop();
			res.push_back((*user_pair.second).second);
			user_pair.second++;
			if (user_pair.second != user_posts[user_pair.first].end()) pq.push(user_pair);
		}
		return res;
	}
	
	/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
	void follow(int followerId, int followeeId) {
		user_relation[followerId].insert(followeeId);
	}
	
	/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
	void unfollow(int followerId, int followeeId) {
		user_relation[followerId].erase(followeeId);
	}
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */

int main(int argc, char *argv[]) {
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i : {1,5,4,6,3,5,7,2}) pq.push(i);
	while (!pq.empty()) {
		cout << pq.top() << endl
		pq.pop();
	}
}