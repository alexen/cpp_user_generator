///
/// random_user_generator.h
///
/// Created on: Sep 19, 2016
///     Author: alexen
///

#pragma once

#include <interface/user_generator.h>
#include <vector>


class RandomMaleGenerator : public IUserGenerator {
private:
     User generate() const override;

     static const std::vector< std::string > surnames_;
     static const std::vector< std::string > names_;
     static const std::vector< std::string > patronymics_;
};


class RandomFemaleGenerator : public IUserGenerator {
private:
     User generate() const override;
};


class RandomUserGenerator : public IUserGenerator {
private:
     User generate() const override;
};
