// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <utility> // For std::pair

// // Function for binary insertion
// void binaryInsert(std::vector<int>& mainChain, int value) {
//     auto pos = std::lower_bound(mainChain.begin(), mainChain.end(), value);
//     mainChain.insert(pos, value);
// }

// // Recursive function implementing the Ford-Johnson sorting process
// std::vector<int> fordJohnsonSort(std::vector<int>& elements) {
//     int n = elements.size();

//     // Base case: Sort directly if the size is less than 3
//     if (n < 3) {
//         std::sort(elements.begin(), elements.end());
//         return elements;
//     }

//     // Step 1: Divide into pairs
//     std::vector<std::pair<int, int>> pairs;
//     std::vector<int> pending;
//     for (size_t i = 0; i + 1 < n; i += 2) {
//         pairs.emplace_back(elements[i], elements[i + 1]);
//     }
//     // If there's a leftover element, put it in Pending
//     if (n % 2 != 0) {
//         pending.push_back(elements.back());
//     }

//     // Step 2: Sort each pair
//     for (auto& p : pairs) {
//         if (p.first > p.second) {
//             std::swap(p.first, p.second); // Ensure smaller in 'a' and larger in 'b'
//         }
//     }

//     // Step 3: Create Main Chain with a(0) and all 'b' values
//     std::vector<int> mainChain;
//     mainChain.push_back(pairs[0].first); // Start with a(0)
//     for (const auto& p : pairs) {
//         mainChain.push_back(p.second); // Add all 'b' values
//     }

//     // Step 4: Recursively sort Main Chain
//     mainChain = fordJohnsonSort(mainChain);

//     // Step 5: Sort pairs using the sorted Main Chain
//     for (auto& p : pairs) {
//         auto aPos = std::lower_bound(mainChain.begin(), mainChain.end(), p.first);
//         auto bPos = std::lower_bound(mainChain.begin(), mainChain.end(), p.second);
//         if (aPos > bPos) {
//             std::swap(p.first, p.second); // Ensure order relative to Main Chain
//         }
//     }

//     // Step 6: Add all a(1), a(2), ..., a(n) into Pending
//     for (size_t i = 1; i < pairs.size(); ++i) {
//         pending.push_back(pairs[i].first);
//     }

//     // Step 7: Insert Pending into Main Chain using binary insertion
//     for (int value : pending) {
//         binaryInsert(mainChain, value);
//     }

//     return mainChain;
// }

// // Driver function
// int main() {
//     std::vector<int> elements = {5, 2, 1, 9, 3, 7, 0, 5 ,84,489,487,31,0,54,897,9784,515,654,62,54,8,46,78,9,62,15,452,3546,6};

//     std::cout << "Original list: ";
//     for (int num : elements) {
//         std::cout << num << " ";
//     }
//     std::cout << "\n";

//     std::vector<int> sortedList = fordJohnsonSort(elements);

//     std::cout << "Sorted list: ";
//     for (int num : sortedList) {
//         std::cout << num << " ";
//     }
//     std::cout << "\n";

//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> // For std::pair

// Function for binary insertion
void binaryInsert(std::vector<int>& mainChain, int value) {
    std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), value);
    mainChain.insert(pos, value);
}

// Recursive function implementing the Ford-Johnson sorting process
std::vector<int> fordJohnsonSort(std::vector<int>& elements) {
    int n = elements.size();

    // Base case: Sort directly if the size is less than 3
    if (n < 3) {
        std::sort(elements.begin(), elements.end());
        return elements;
    }

    // Step 1: Divide into pairs
    std::vector<std::pair<int, int> > pairs;
    std::vector<int> pending;
    for (int i = 0; i + 1 < n; i += 2) {
        pairs.push_back(std::make_pair(elements[i], elements[i + 1]));
    }
    if (n % 2 != 0) {
        pending.push_back(elements.back());
    }

    // Step 2: Sort each pair
    for (size_t i = 0; i < pairs.size(); ++i) {
        if (pairs[i].first > pairs[i].second) {
            std::swap(pairs[i].first, pairs[i].second);
        }
    }

    // Step 3: Create Main Chain with a(0) and all 'b' values
    std::vector<int> mainChain;
    mainChain.push_back(pairs[0].first);
    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].second);
    }

    // Step 4: Recursively sort Main Chain
    mainChain = fordJohnsonSort(mainChain);

    // Step 5: Sort pairs using the sorted Main Chain
    for (size_t i = 0; i < pairs.size(); ++i) {
        std::vector<int>::iterator aPos = std::lower_bound(mainChain.begin(), mainChain.end(), pairs[i].first);
        std::vector<int>::iterator bPos = std::lower_bound(mainChain.begin(), mainChain.end(), pairs[i].second);
        if (aPos > bPos) {
            std::swap(pairs[i].first, pairs[i].second);
        }
    }

    // Step 6: Add all 'a' values except a(0) to Pending
    for (size_t i = 1; i < pairs.size(); ++i) {
        pending.push_back(pairs[i].first);
    }

    // Step 7: Binary insert all pending elements into the Main Chain
    for (size_t i = 0; i < pending.size(); ++i) {
        binaryInsert(mainChain, pending[i]);
    }

    return mainChain;
}

// Driver function to test the Ford-Johnson algorithm
int main() {
    std::vector<int> elements;
    elements.push_back(5);
    elements.push_back(2);
    elements.push_back(1);
    elements.push_back(9);
    elements.push_back(3);
    elements.push_back(7);
    elements.push_back(0);

    std::cout << "Original List: ";
    for (size_t i = 0; i < elements.size(); ++i) {
        std::cout << elements[i] << " ";
    }
    std::cout << std::endl;

    std::vector<int> sortedList = fordJohnsonSort(elements);

    std::cout << "Sorted List: ";
    for (size_t i = 0; i < sortedList.size(); ++i) {
        std::cout << sortedList[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
