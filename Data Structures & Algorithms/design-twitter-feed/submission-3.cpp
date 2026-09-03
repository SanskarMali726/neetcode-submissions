class Twitter {
public:
    int time = 0;

    class Node{
        public:
            int user_id;
            vector<Node*> follow;
            priority_queue<pair<int,int>, vector<pair<int,int>> > tweet;
            Node* next;

            // Node(int uID,Node* f,int tID){
            //     user_id = uID;
            //     follow.push_back(f);
            //     tweet.push(tID);
            //     next = NULL;
            // }

            Node(int uID,pair<int,int> tw){
                user_id = uID;
                tweet.push(tw);
                next = NULL;
            }

            Node(int uID) {
                user_id = uID;
                next = NULL;
            }
    };

    Twitter() {
        
    }

    Node* head = new Node(0,{-1,-1});
    Node* tail = head;
    Node* temp = head;
    
    void postTweet(int userId, int tweetId) {
        temp = head->next;
        while(temp){
            if(temp->user_id == userId){
                break;
            }
            temp = temp->next;
        }
        
        if(temp == NULL){
            pair<int,int> t(time,tweetId);
            Node* newUser = new Node(userId,t);
            tail->next = newUser;
            tail = tail->next;
        }
        else{
            temp->tweet.push({time,tweetId});
        }

        time++;
    }

    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        temp = head->next;
        while(temp->user_id != userId){
            temp = temp->next;
        }
    
        vector<Node*> following = temp->follow;
        priority_queue<pair<int,int>, vector<pair<int,int>> > all = temp->tweet;
        

        for(auto x : following){
            priority_queue<pair<int,int>, vector<pair<int,int>>> t = x->tweet;

            int count = 0;
            while(!t.empty() && count < 10){
                all.push(t.top());
                t.pop();
                count++;
            }
        }
        

        int count = 0;
        while(!all.empty() && count < 10){
            ans.push_back(all.top().second);
            all.pop();
            count++;
            
        }
        
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;

        Node* follower = NULL;
        Node* followee = NULL;

        temp = head->next;

        while (temp) {
            if (temp->user_id == followerId) {
                follower = temp;
            }

            if (temp->user_id == followeeId) {
                followee = temp;
            }

            if (follower && followee) {
                break;
            }

            temp = temp->next;
        }

        if (follower == NULL) {
            follower = new Node(followerId);
            tail->next = follower;
            tail = follower;
        }

        if (followee == NULL) {
            followee = new Node(followeeId);
            tail->next = followee;
            tail = followee;
        }

        if (find(follower->follow.begin(),
                follower->follow.end(),
                followee) == follower->follow.end()) {
            follower->follow.push_back(followee);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        temp = head->next;
        while(temp->user_id != followerId){
            temp = temp->next;
        }
        Node* follower = temp;
        temp = head->next;

        while(temp->user_id != followeeId){
            temp = temp->next;
        }

        auto it = find(follower->follow.begin(), follower->follow.end(), temp);

        if(it != follower->follow.end()){
            follower->follow.erase(it);
        }
    }
};
