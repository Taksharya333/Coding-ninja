class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
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

    bool insertWord(TrieNode *root, string word) {
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
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word) {
        if (insertWord(root, word)) {
            this->count++;
        }
    }
     void searchWord(TrieNode *root, string word,int index, string ans)
    {
    
     if(root==NULL){
         cout << ans << endl;
      return;
     }
     if (index < word.length()) {
       int ind = word[index] - 'a';
       if(root->children[ind] != NULL && index==word.length()-1 && root->children[ind]->isTerminal)cout<<word<<endl;
         if (root->children[ind] != NULL) {
           searchWord(root->children[ind], word, index + 1, ans + word[index]);
         }
         else return;
     }
     else{
        for (int i = 0; i < 26; i++) {

          if (root->children[i] != NULL) {
            if (root->children[i]->isTerminal)
              cout << ans+root->children[i]->data << endl;
            searchWord(root->children[i], word, index + 1, ans + root->children[i]->data);
          }
        }
        if(root->data==ans.back())return;
        else  cout << ans+root->data << endl;
     }
    }
    void search(string word) {
        // Write your code here
    searchWord(root,word,0,"");
    }
    void autoComplete(vector<string> input, string pattern) {
        // Write your code here
        for(string s: input)
       insertWord(s);
        search(pattern);
    }
};