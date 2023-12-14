#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <valarray>

using std::cout;    using std::endl;
using std::ifstream; using std::string;
using std::vector;

// feature vectors
const vector<string> FEATURE_VEC{"a", "about", "above", "after", "again", "against", "all", "am", "an", "and",
                                "any", "are", "aren't", "as", "at", "be", "because", "been", "before", "being",
                                "below", "between", "both", "but", "by", "can't", "cannot", "could", "couldn't",
                                "did", "didn't", "do", "does", "doesn't", "doing", "don't", "down", "during",
                                "each", "few", "for", "from", "further", "had", "hadn't", "has", "hasn't", "have",
                                "haven't", "having", "he", "he'd", "he'll", "he's", "her","here", "here's", "hers",
                                "herself", "him", "himself", "his", "how", "how's", "i", "i'd", "i'll", "i'm",
                                "i've", "if", "in", "into", "is", "isn't", "it", "it's", "its", "itself", "let's",
                                "me", "more", "most", "mustn't", "my", "myself", "no", "nor", "not", "of", "off",
                                "on", "once", "only", "or", "other", "ought", "our", "ours", "ourselves", "out",
                                "over", "own", "same", "shan't", "she", "she'd", "she'll", "she's", "should",
                                "shouldn't", "so", "some", "such", "than", "that", "that's", "the", "their",
                                "theirs", "them", "themselves", "then", "there", "there's", "these", "they",
                                "they'd", "they'll", "they're", "they've", "this", "those", "through", "to", "too",
                                "under", "until", "up", "very", "was", "wasn't", "we", "we'd", "we'll", "we're",
                                "we've", "were", "weren't", "what", "what's", "when", "when's", "where", "where's",
                                "which", "while", "who", "who's", "whom", "why", "why's", "with", "won't", "would",
                                "wouldn't", "you", "you'd", "you'll", "you're", "you've", "your", "yours",
                                "yourself", "yourselves", "!", "\"", "#", "$", "%", "&", "'", "(", ")", "*", "+",
                                ",", "-", ".", "/", ":", ";", "<", "=", ">", "?", "@", "[", "\\", "]", "^", "_",
                                "`", "{", "|", "}", "~"};

string fileToString(ifstream& file) {
    string ret = "";
    string line;
    while (std::getline(file, line)) {
        // std::transform will perform an operation over a range
        std::transform(line.begin(), line.end(), line.begin(), tolower);
        ret += line + " ";
    }
    return ret;
}

int countOccurences(const string& word, const string& text) {
    string toFind = " " + word + " ";
    auto curr = text.begin();    
    auto end = text.end();
    int count = 0;
    while (curr != end) {
        auto found = std::search(curr, end, toFind.begin(), toFind.end());
        if (found == end) break;
        count++;
        curr = found + 1;
    }
    return count;    
}

vector<int> createFreqVec(const string& string) {
    vector<int> result;
    for (const auto& word: FEATURE_VEC) {
        result.push_back(countOccurences(word, string));
    }
    return result;
}

int dotProduct(vector<int> v1, vector<int> v2) {
    return std::inner_product(v1.begin(), v1.end(), v2.begin(), 0);
}

int mag(vector<int>& v) {
    return std::sqrt(dotProduct(v, v));
}

double getSimilarity(const string& text1, const string& text2) {
    vector<int> freqVec1 = createFreqVec(text1);
    vector<int> freqVec2 = createFreqVec(text2);
    int dotProd = dotProduct(freqVec1, freqVec2);
    return dotProd / mag(freqVec1) * mag(freqVec2);
}

int main() {
    ifstream file1("madison.txt");
    if (!file1.is_open()) {
        std::cerr << "无法打开文件" << std::endl;
        return 1;
    }
    cout << "成功打开" << endl;
    string f_mad = fileToString(file1);
    cout << f_mad << endl;
    return 0;
}
