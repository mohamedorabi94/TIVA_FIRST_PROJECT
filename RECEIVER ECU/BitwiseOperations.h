/*
 * BitwiseOperations.h
 *
 * Created: 2/13/2019 11:38:14 AM
 *  Author: AVE-LAP-032
 */ 

#ifndef BITWISEOPERATIONS_H_
#define BITWISEOPERATIONS_H_

#define ONE 1

#define SET_BIT(REG,BIT)     ( REG |= (  ONE<< (BIT)  ) )

#define CLEAR_BIT(REG,BIT)   ( REG &= (~(ONE<<(BIT)   ) )  )

#define GET_BIT(REG,BIT)     ( (REG & (ONE<<(BIT)) )>>(BIT))

#define TOGGLE_BIT(REG,BIT)  ( REG ^=  (ONE<<(BIT)  )  )


#endif /* BITWISEOPERATIONS_H_ */
