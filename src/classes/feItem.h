#ifndef ITEM_H
#define ITEM_H

#include <string>

class feItem {
	protected:
		std::string name;
		int usages;
	public:
		/**
		 * std::string check()
		 * @return a string that can be matched against to
		 * determine if a character can call use().
		 */
		virtual std::string check() = 0;
		/**
		 * void print()
		 * Plaintext printing for debugging or informational
		 * purposes.
		 */
		virtual void print() = 0;
		/**
		 * void use()
		 * Use this item.
		 */
		virtual void use() = 0;
};

#endif
