#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <iomanip>

struct MemoryInfo {
    long totalMemory;    
    long freeMemory;     
    long availableMemory;
    long buffers;        
    long cached;         
};

class RamMonitorI {
public:
    virtual ~RamMonitorI() = default;
    virtual MemoryInfo getMemoryInfo() const = 0;
    virtual void displayMemoryInfo() const = 0;
};

class RamMonitor : public RamMonitorI {
private:
    static const int LABEL_WIDTH = 20; // Width for labels (adjustable)

public:
    MemoryInfo getMemoryInfo() const override {
        std::ifstream meminfoFile("/proc/meminfo");
        if (!meminfoFile.is_open()) {
            throw std::runtime_error("Unable to open /proc/meminfo");
        }

        MemoryInfo memInfo{};
        std::string line;
        while (std::getline(meminfoFile, line)) {
            std::istringstream iss(line);
            std::string key;
            long value;
            std::string unit;
            iss >> key >> value >> unit;

            if (key == "MemTotal:") {
                memInfo.totalMemory = value;
            } else if (key == "MemFree:") {
                memInfo.freeMemory = value;
            } else if (key == "MemAvailable:") {
                memInfo.availableMemory = value;
            } else if (key == "Buffers:") {
                memInfo.buffers = value;
            } else if (key == "Cached:") {
                memInfo.cached = value;
            }
        }

        meminfoFile.close();
        return memInfo;
    }

    void displayMemoryInfo() const override {
        MemoryInfo memInfo = getMemoryInfo();
        double usedMemory = memInfo.totalMemory - memInfo.availableMemory;
        double usedPercentage = (usedMemory / memInfo.totalMemory) * 100.0;
        double freePercentage = 100.0 - usedPercentage;

        std::cout << "Memory Information (in KB | in MB | in GB):" << std::endl;

        displayCategory("Total Memory", memInfo.totalMemory);
        displayCategory("Free Memory", memInfo.freeMemory);
        displayCategory("Available Memory", memInfo.availableMemory);
        displayCategory("Buffers", memInfo.buffers);
        displayCategory("Cached", memInfo.cached);

        std::cout << "\nPercentage Usage:" << std::endl;
        std::cout << std::setw(LABEL_WIDTH) << "Used:" 
                  << std::fixed << std::setprecision(2) 
                  << usedPercentage << "%" << std::endl;

        std::cout << std::setw(LABEL_WIDTH) << "Free:" 
                  << freePercentage << "%" << std::endl;
    }

private:
    void displayCategory(const std::string& label, long valueKB) const {
        double valueMB = valueKB / 1024.0;
        double valueGB = valueMB / 1024.0;

        std::cout << std::setw(LABEL_WIDTH) << label << ": ";
        std::cout << std::setw(10) << valueKB << " KB | ";
        std::cout << std::setw(10) << std::fixed << std::setprecision(2) << valueMB << " MB | ";
        std::cout << std::setw(10) << valueGB << " GB" << std::endl;
    }
};

int main() {
    try {
        RamMonitor monitor;
        monitor.displayMemoryInfo();
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

