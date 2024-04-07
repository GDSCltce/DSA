#include <bits/stdc++.h>
using namespace std;

class Trie
{
    struct Node
    {
        Node *links[26];
        int end = 0, prefix= 0;
        Node()
        {
            for (int i = 0; i < 26; i++)
                links[i] = NULL;
        }
        bool containKey(char x)
        {
            return (links[x - 'a'] != NULL);
        }
        void put(char x, Node *node)
        {
            links[x - 'a'] = node;
        }
        Node *get(char x)
        {
            return links[x - 'a'];
        }
        void setEnd()
        {
            end = true;
        }
        bool isEnd()
        {
            return end;
        }
        void increaseEnd() { end++; }
        void decreaseEnd() { end--; }
        void increasePrefix() { prefix++; }
        void decreasePrefix() { prefix--; }
        int getEnd() { return end; }
        int getPrefix() { return prefix; }
    };
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }
    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containKey(word[i]))
                node->put(word[i], new Node());
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }
    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containKey(word[i]))
                return false;
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    bool prefix(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containKey(word[i]))
                return false;
            node = node->get(word[i]);
        }
        return true;
    }
    int countWordsEqualTo(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containKey(word[i]))
                node = node->get(word[i]);
            else
                return 0;
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containKey(word[i]))
                node = node->get(word[i]);
            else
                return 0;
        }
        return node->getPrefix();
    }
    void erase(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containKey(word[i]))
            {
                node = node->get(word[i]);
                node->decreasePrefix();
            }
            else
                return;
        }
        node->decreaseEnd();
    }
};

signed main()
{
    Trie *root = new Trie();
    root->insert("bad");
    root->insert("apps");
    root->insert("bac");
    root->insert("apple");

    cout << root->prefix("apps") << " ";
    cout << root->search("apps");
    return 0;
}