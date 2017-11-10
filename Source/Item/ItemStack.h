#ifndef ITEMSTACK_H_INCLUDED
#define ITEMSTACK_H_INCLUDED

#include "../World/Block/Block.h"
#include "../World/Block/BlockDB.h"

class ItemStack
{
    public:
        ItemStack(const Block& block, int amount);

        int add(int amount);
        void remove();

        int getNumInStack() const;

        const Block& getBlocktype() const;

    private:
        const Block*    m_pBlock;
        int             m_numInStack = 0;

};

#endif // ITEMSTACK_H_INCLUDED
