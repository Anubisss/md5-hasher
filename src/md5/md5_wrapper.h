/*
 *    Feb. 2005
 *    Benjamin Grüdelbach
 */

/*
 * MD5 string/file hasher written in C++.
 * Copyright (C) 2009  David Vas, Anubisss
 * <http://code.google.com/p/md5-hasher/>

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _MD5WRAPPER_H_
#define _MD5WRAPPER_H_

#include <string>

class MD5;

class md5wrapper
{
    private:
        MD5 *md5;

        /*
         * internal hash function, calling
         * the basic methods from md5.h
         */
        std::string hashit(std::string text);

        /*
         * converts the numeric giets to
         * a valid std::string
         */
        std::string convToString(unsigned char *bytes);

    public:
        //constructor
        md5wrapper();

        //destructor
        ~md5wrapper();

        /*
         * creates a MD5 hash from
         * "text" and returns it as
         * string
         */
        std::string getHashFromString(std::string text);

        /*
         * creates a MD5 hash from
         * a file specified in "filename" and
         * returns it as string
         */
        std::string getHashFromFile(std::string filename);
};

#endif

/*
 * EOF
 */
