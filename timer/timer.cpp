#include <iostream>
#include <chrono>
#include <thread>

class Timer {
private:
    std::chrono::time_point<std::chrono::steady_clock> start_time;
    const int durationHours = 12; // Timer duration in hours
    bool is_initialized = false;  // Tracks if the function has been called for the first time

public:
    int getCurrentTime() {
        if (!is_initialized) {
            // Initialize the start time at the first call (assume it's 7:00 AM)
            start_time = std::chrono::steady_clock::now();
            is_initialized = true;
            return 1; // Timer active
        }

        // Calculate the elapsed time
        auto now = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::hours>(now - start_time).count();

        // Check if the timer has exceeded the duration
        if (elapsed >= durationHours) {
            return 0; // Time's up, flag off
        } else {
            return 1; // Timer still active
        }
    }
};

int main() {
    Timer timer;

    while (true) {
       extern int flag = timer.getCurrentTime();

        if (flag == 0) {
			// db.checkpoint();
			// save_rank
            std::cout << "It's 7:00 PM. Timer finished!" << std::endl;
            // Perform shutdown or any other final task
			system("sudo shutdown now");
			
            break;
        } else {
		
            //std::cout << "Timer is active. Still waiting..." << std::endl;
        }

        // Sleep for a while before checking again (e.g., 1 minute)
        std::this_thread::sleep_for(std::chrono::minutes(1));	
    }

    return 0;
}
