// Problem: https://www.hackerrank.com/challenges/attribute-parse

#include <bits/stdc++.h>
using namespace std;

class Tag {
   private:
    string tag_name;

   public:
    Tag *parent = nullptr;
    unordered_map<string, string> attributes;
    unordered_map<string, Tag *> subTags;

    Tag(string name) {
        this->tag_name = name;
    }

    string GetName() {
        return this->tag_name;
    }

    void AddAttribute(string &key, string &value) {
        this->attributes[key] = value;
    }

    Tag *CreateNewSubTag(string &sub_tag_name) {
        Tag *subTag = new Tag(sub_tag_name);
        this->subTags[sub_tag_name] = subTag;
        return subTag;
    }

    void AddSubTag(Tag *sub_tag) {
        this->subTags[sub_tag->GetName()] = sub_tag;
    }

    void Print() {
        cout << this->tag_name << " ";
        for (auto each : this->attributes) {
            cout << each.first << " = " << each.second << " ";
        }
        cout << "\n";
        for (auto each : this->subTags) {
            each.second->Print();
        }
        cout << "End " << this->tag_name << "\n";
    }
};

vector<string> split_words(string &line, char delimeter) {
    vector<string> words;
    string temp;
    auto ss = stringstream(line);
    while (getline(ss, temp, delimeter)) {
        words.push_back(temp);
    }
    return words;
}

class TagLineParser {
   private:
    string trim(string &word) {
        string trimmed_string;
        for (auto c : word) {
            if (c == '<' || c == '>' || c == '"') {
                continue;
            }
            trimmed_string.push_back(c);
        }
        return trimmed_string;
    }

   public:
    Tag *ParseLine(string line) {
        if (line[1] != '/') {
            auto words = split_words(line, ' ');
            Tag *tag = new Tag(trim(words[0]));
            for (int i = 1; i < words.size(); i += 3) {
                string attr_name = trim(words[i]);
                string attr_value = trim(words[i + 2]);
                tag->AddAttribute(attr_name, attr_value);
            }
            return tag;
        }
        return nullptr;
    }
};

class QueryParser {
   public:
    vector<string> Parse(string line) {
        auto words = split_words(line, '.');
        auto last = words[words.size() - 1];
        words.pop_back();
        auto lasttwo = split_words(last, '~');
        words.push_back(lasttwo[0]);
        words.push_back(lasttwo[1]);
        return words;
    }
};

string findValue(Tag *tag, vector<string> &path, string attr_name) {
    if (tag == nullptr) {
        return "Not Found!";
    }

    vector<pair<Tag *, int>> stack;
    stack.push_back({tag, 0});
    Tag *target_tag = nullptr;
    while (!stack.empty()) {
        auto pair = stack.back();
        stack.pop_back();
        Tag *tag = pair.first;
        int pathi = pair.second;
        if (tag->GetName() == path[pathi]) {
            if (pathi == path.size() - 1) {
                target_tag = tag;
                break;
            }
            for (auto subtag : tag->subTags) {
                stack.push_back({subtag.second, pathi + 1});
            }
        }
    }

    if (target_tag == nullptr) {
        return "Not Found!";
    }

    if (target_tag->attributes.find(attr_name) == target_tag->attributes.end()) {
        return "Not Found!";
    }

    return target_tag->attributes[attr_name];
}

int main() {
    TagLineParser tgp;
    QueryParser qp;
    int n, q;
    cin >> n >> q;
    string line;
    getline(cin, line);

    Tag *head = new Tag("document");
    Tag *curr = head;
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        Tag *tag = tgp.ParseLine(line);
        if (tag == nullptr) {
            curr = curr->parent;
        } else {
            tag->parent = curr;
            curr->AddSubTag(tag);
            curr = tag;
        }
    }

    for (int i = 0; i < q; i++) {
        getline(cin, line);
        auto query = qp.Parse("document." + line);
        string att_name = query.back();
        query.pop_back();
        cout << findValue(head, query, att_name) << "\n";
    }
}
