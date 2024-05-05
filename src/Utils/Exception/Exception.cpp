/**
 * @file Exception.cpp
 * @author COUSTABEAU Maxime (maxime.coustabeau@epitech.eu)
 *         GIRARD Anthony (anthony1.girard@epitech.eu)
 *         MERY Baptiste (baptiste.mery@epitech.eu)
 *         AUDIBERT Nicolas (nicolas.audibert@epitech.eu)
 * @brief EPITECH PROJECT, 2024
 * @version 0.1
 * @date 2024-05-03
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "Exception.hpp"

/**
 * @brief Construct a new Exception:: Exception object
 *
 * @param errorMsg The error message associated with the exception.
 * @details Initializes a new Exception object with the provided error message.
 */
Exception::Exception(const std::string &errorMsg) noexcept : _error(errorMsg) {}

/**
 * @brief Destroy the Exception:: Exception object
 *
 * @details Destructor for the Exception object.
 */
Exception::~Exception() {};

/**
 * @brief Returns the error message associated with the exception.
 *
 * @return const char* A pointer to the C-style string containing the error message.
 */
const char *Exception::what() const noexcept
{
    return _error.c_str();
}
