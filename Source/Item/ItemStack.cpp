#include "ItemStack.h"

#include <algorithm>

ItemStack::ItemStack(const Block& block, int amount)
:   m_pBlock     (&block)
,   m_numInStack    (amount)
{ }

int ItemStack::add(int amount)
{
    m_numInStack += amount;

    if (m_numInStack > m_pBlock->maxStackSize)
    {
        int leftOver = m_numInStack - m_pBlock->maxStackSize;
        m_numInStack = m_pBlock->maxStackSize;
        return leftOver;
    }
    else
    {
        return 0;
    }
}

void ItemStack::remove()
{
    m_numInStack--;
    if (m_numInStack == 0)
    {
        m_pBlock = &BlockDB::get()[2]/*Nothing*/;
    }
}

int ItemStack::getNumInStack() const
{
    return m_numInStack;
}

const Block& ItemStack::getBlocktype() const
{
    return *m_pBlock;
}
