#include "map"
#include "vector"
#include "chrono"
#include "iostream"

struct Event {
    std::string name;
    std::string message;
    std::string description;
    int level;
    std::string action;
    bool isActive;
    std::chrono::time_point<std::chrono::steady_clock> timestamp;
    uint8_t ttl;
    std::string target;
    std::string source;
    std::vector<std::string> route;
    std::map<std::string, std::string> meta;
};


class EventBuilder {
public:
    explicit EventBuilder(const std::string& event_name) {
        event.name = event_name;
        event.description = "This is " + event_name;
        event.timestamp = std::chrono::steady_clock::now();
    }

    Event BuildEvent() noexcept {
        if (event.source.empty() && !event.route.empty()) {
            event.source = event.route.front();
        }
        if (event.target.empty() && !event.route.empty()) {
            event.target = event.route.back();
        }
        return event;
    }
    EventBuilder& AddLevel(int level) noexcept {
        event.level = level;
        return *this;
    }

    EventBuilder& AddMeta(const std::string& key, const std::string& value) {
        event.meta[key] = value;
        return *this;
    }
    EventBuilder& AddRoutePoint(const std::string& point) {
        event.route.push_back(point);
        return *this;
    }
private:
    Event event;
};

void SendEvent(const Event& e) {
    std::cout << "Sending event " << e.name << " to " << e.target << " from " << e.source << std::endl;
    std::cout << "route is: \n";
    for (const auto& point: e.route) {
        std::cout << point << "->";
    }
}

int main() {
    EventBuilder builder("VeryImportantEvent");
    builder.AddLevel(3).AddMeta("key", "value");
    builder.AddRoutePoint("first").AddRoutePoint("second");
    SendEvent(builder.BuildEvent());
}
