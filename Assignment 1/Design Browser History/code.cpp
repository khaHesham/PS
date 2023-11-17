
class BrowserHistory {
public:
    std::vector<std::string> history;  // can be implemented also using double linkedList
    int currentIndex;

    BrowserHistory(std::string homepage) {
        history.push_back(homepage);
        currentIndex = 0;  // Start at the beginning of the history.
    }

    void visit(std::string url) {
        // visiting url clears our history
        history.resize(currentIndex + 1);
        history.push_back(url);
        currentIndex++;
    }

    std::string back(int steps) {
        // Go back in history N-steps
        currentIndex = std::max(0, currentIndex - steps);
        return history[currentIndex];
    }

    std::string forward(int steps) {
        // Go forward in history N-steps
        currentIndex = std::min(int(history.size()) - 1, currentIndex + steps);
        return history[currentIndex];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */