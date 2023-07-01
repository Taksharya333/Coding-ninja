class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool add(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }

        // Recursive call
        return add(child, word.substr(1));
    }

    void add(string word) {
        if (add(root, word)) {
            this->count++;
        }
    }
   bool searchWord(TrieNode *root, string word, int index, int n)
    {
     if(index==n)return true;
     if(root==NULL)return false;
      int ind = word[index] - 'a';
      if (root->children[ind] != NULL && searchWord(root->children[ind], word, index+1, n))return true;
      if(index==0){
      for(int i=0;i<26;i++)
        {
            if (root->children[i] != NULL && searchWord(root->children[i], word, index, n)) return true;
        }
      }
      return false;
    }
    bool search(string word) {
        // Write your code here
      int size = word.length();
      int i = 0;
      return searchWord(root,word, i, size);
    }

    /*..................... Palindrome Pair................... */

    bool isPalindromePair(vector<string> words) {
        // Write your code here
        for(string s: words)
        {
            string temp= s;
            reverse(s.begin(),s.end());
            if(s==temp)return true;
           add(s);
        }
        for(string s: words)
        {
           
             if(search(s))return true;
        }

        return false;
    }
};