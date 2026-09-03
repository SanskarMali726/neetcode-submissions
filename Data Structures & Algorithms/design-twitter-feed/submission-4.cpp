class Twitter {
public:
    // Used to give every tweet a unique increasing timestamp.
    // Higher time = more recent tweet.
    int time = 0;

    class Node {
    public:
        int user_id;

        // Stores pointers to users this user follows.
        vector<Node*> follow;

        // Stores {timestamp, tweetId}.
        // priority_queue keeps the tweet with the largest timestamp on top.
        priority_queue<pair<int,int>, vector<pair<int,int>>> tweet;

        // Linked list pointer to the next user.
        Node* next;

        // Constructor used when creating a user with their first tweet.
        Node(int uID, pair<int,int> tw) {
            user_id = uID;
            tweet.push(tw);
            next = NULL;
        }

        // Constructor used when creating a user without any tweet.
        Node(int uID) {
            user_id = uID;
            next = NULL;
        }
    };

    Twitter() {
        
    }

    // Dummy head node.
    // Actual users start from head->next.
    Node* head = new Node(0, {-1, -1});

    // Tail always points to the last user in the linked list.
    Node* tail = head;

    // Temporary pointer used for traversing the linked list.
    Node* temp = head;


    void postTweet(int userId, int tweetId) {

        // Search for the user in the linked list.
        temp = head->next;

        while (temp) {
            if (temp->user_id == userId) {
                break;
            }

            temp = temp->next;
        }

        // If user doesn't exist, create a new user.
        if (temp == NULL) {

            // Store {timestamp, tweetId}.
            pair<int,int> t(time, tweetId);

            Node* newUser = new Node(userId, t);

            // Add the new user at the end of linked list.
            tail->next = newUser;
            tail = tail->next;
        }
        else {
            // User already exists, so simply add the tweet.
            temp->tweet.push({time, tweetId});
        }

        // Increase time after every tweet.
        time++;
    }


    vector<int> getNewsFeed(int userId) {
        vector<int> ans;

        // Find the user in the linked list.
        temp = head->next;

        // temp && prevents accessing temp->user_id when temp becomes NULL.
        while (temp && temp->user_id != userId) {
            temp = temp->next;
        }

        // User doesn't exist, so there is no news feed.
        if (!temp)
            return ans;

        // Copy all users that this user follows.
        vector<Node*> following = temp->follow;

        // Start with the user's own tweets.
        priority_queue<pair<int,int>, vector<pair<int,int>>> all = temp->tweet;


        // Add tweets from every followed user.
        for (auto x : following) {

            // Copy that user's tweet heap.
            priority_queue<pair<int,int>, vector<pair<int,int>>> t = x->tweet;

            int count = 0;

            // We only need the 10 most recent tweets from each user.
            while (!t.empty() && count < 10) {

                // Since priority_queue is a max heap,
                // t.top() is the most recent tweet.
                all.push(t.top());

                t.pop();
                count++;
            }
        }


        int count = 0;

        // all contains tweets from the user + followed users.
        // Get the 10 most recent tweets overall.
        while (!all.empty() && count < 10) {

            // pair = {timestamp, tweetId}
            // We only need tweetId in the answer.
            ans.push_back(all.top().second);

            all.pop();
            count++;
        }

        return ans;
    }


    void follow(int followerId, int followeeId) {

        // A user cannot follow themselves.
        if (followerId == followeeId)
            return;

        Node* follower = NULL;
        Node* followee = NULL;

        // Search for both users in the linked list.
        temp = head->next;

        while (temp) {

            if (temp->user_id == followerId) {
                follower = temp;
            }

            if (temp->user_id == followeeId) {
                followee = temp;
            }

            // Stop searching once both users are found.
            if (follower && followee) {
                break;
            }

            temp = temp->next;
        }


        // If follower doesn't exist, create the user.
        if (follower == NULL) {
            follower = new Node(followerId);

            tail->next = follower;
            tail = follower;
        }


        // If followee doesn't exist, create the user.
        if (followee == NULL) {
            followee = new Node(followeeId);

            tail->next = followee;
            tail = followee;
        }


        // Check whether follower is already following followee.
        // We store Node* pointers in the follow vector,
        // so find() compares the pointers.
        if (find(follower->follow.begin(),
                 follower->follow.end(),
                 followee) == follower->follow.end()) {

            // Not already following -> add followee.
            follower->follow.push_back(followee);
        }
    }


    void unfollow(int followerId, int followeeId) {

        // Find the follower.
        temp = head->next;

        // temp && prevents NULL pointer access.
        while (temp && temp->user_id != followerId) {
            temp = temp->next;
        }

        // Follower doesn't exist.
        if (!temp)
            return;

        Node* follower = temp;


        // Find the followee.
        temp = head->next;

        while (temp && temp->user_id != followeeId) {
            temp = temp->next;
        }

        // Followee doesn't exist.
        if (!temp)
            return;

        Node* followee = temp;


        // Search for the followee inside follower's follow list.
        auto it = find(follower->follow.begin(),
                       follower->follow.end(),
                       followee);


        // If followee is present, remove it.
        if (it != follower->follow.end()) {
            follower->follow.erase(it);
        }
    }
};