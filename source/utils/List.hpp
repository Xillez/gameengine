#pragma once

#include "typedef.hpp"

#include <vector>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <type_traits>
#include <typeinfo>

// ################################################################################################
// #                                                                                              #
// #                                             List                                             #
// #                                                                                              #
// ################################################################################################

/**
 * @brief List class. Contains a set of elements.
 * 
 * @tparam Ttype Class/Type you want to store.
 */
template<class Ttype>
class List
{
public:
    /**
     * @brief Constructor of List.
     */
    List()
    {
        this->list = std::vector<Ttype>();
    }

    // ##########################################
    // ########## Management functions ##########
    // ##########################################

    /**
     * @brief Adds an item to the list.
     * 
     * @param item Item to be added.
     */
    void AddItem(Ttype* item)
    {
        if (item != nullptr)            // If not nothing, add it.
            this->list.push_back(item);
    }

    /**
     * @brief Get the item by index.
     * @attention NOT IMPLEMENTED!
     * 
     * @param index - Index of given item.
     * 
     * @return Ttype* - Pointer to item found. If nothing found, nullptr returned.
     */
    Ttype* GetItemByIndex(int index)
    {
        return nullptr;
    }

    /**
     * @brief Get the index and item is stored.
     * @attention NOT IMPLEMENTED!
     * 
     * @param item - Item to get index of.
     * 
     * @return int - Index of item. Negative if not found.
     */
    int GetItemIndex(Ttype* item)
    {
        return 0;
    }

    /**
     * @brief Get the item by type
     * @attention NOT IMPLEMENTED!
     * 
     * @tparam Tclass - Class/Type to check for.
     * 
     * @return A std::vector of specified type if found.
     */
    template<class Tclass>
    std::vector<Ttype*> GetItemByType()
    {
        return std::vector<Ttype*>();
    }

    /**
     * @brief Removes an item by index.
     * @attention NOT IMPLEMENTED!
     * 
     * @param index Index to be removed.
     *
     */
    void RemoveByIndex(int index)
    {
        //
    }

    /**
     * @brief Removes item. If nullptr is given, entire list is deleted.
     * 
     * @param item - Pointer to item to be destroyed.
     */
    void Remove(Ttype* item = nullptr)
    {
        if (item == nullptr)    // List is supposed to be cleared.
        {
            this->list.clear();
            return;
        }

        this->list.erase(std::find(this->list.begin(), this->list.end(), item));    // Erase if it exists.
    }

    // #######################################
    // ########## Utility functions ##########
    // #######################################

    /**
     * @brief A built-in ForEach loop calling given function for every item registered (with its respective index).
     * 
     * @param func - Function to call for each item. Function signature: void(*func)(int, Ttype*).
     */
    void ForEachItem(std::function<void(int, Ttype*)> func)
    {
        for (int i = 0; i < this->data.size(); i++)
        {
            func(i, this->data[i]);
        }
    }

    /**
     * @brief Returns the list as std::vector.
     * 
     * @return An std::vector containing all items.
     */
    std::vector<Ttype*> RawVector()
    {
        return this->data;
    }

protected:
    //
private:
    std::vector<Ttype*> list;      //!< A vector of all registered items.
};