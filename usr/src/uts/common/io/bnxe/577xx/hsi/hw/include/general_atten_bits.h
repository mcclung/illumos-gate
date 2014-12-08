#define RESERVED_GENERAL_ATTENTION_BIT_0        0

#define EVEREST_GEN_ATTN_IN_USE_MASK 		0x7ffe0
#define EVEREST_LATCHED_ATTN_IN_USE_MASK 	0xffe00000

#define RESERVED_GENERAL_ATTENTION_BIT_6        6
#define RESERVED_GENERAL_ATTENTION_BIT_7        7
#define RESERVED_GENERAL_ATTENTION_BIT_8        8
#define RESERVED_GENERAL_ATTENTION_BIT_9        9
#define RESERVED_GENERAL_ATTENTION_BIT_10       10
#define RESERVED_GENERAL_ATTENTION_BIT_11       11
#define RESERVED_GENERAL_ATTENTION_BIT_12       12
#define RESERVED_GENERAL_ATTENTION_BIT_13       13
#define RESERVED_GENERAL_ATTENTION_BIT_14       14
#define RESERVED_GENERAL_ATTENTION_BIT_15       15
#define RESERVED_GENERAL_ATTENTION_BIT_16       16
#define RESERVED_GENERAL_ATTENTION_BIT_17       17
#define RESERVED_GENERAL_ATTENTION_BIT_18       18
#define RESERVED_GENERAL_ATTENTION_BIT_19       19
#define RESERVED_GENERAL_ATTENTION_BIT_20       20
#define RESERVED_GENERAL_ATTENTION_BIT_21     	21

/* storm asserts attention bits */
#define TSTORM_FATAL_ASSERT_ATTENTION_BIT     RESERVED_GENERAL_ATTENTION_BIT_7
#define USTORM_FATAL_ASSERT_ATTENTION_BIT     RESERVED_GENERAL_ATTENTION_BIT_8
#define CSTORM_FATAL_ASSERT_ATTENTION_BIT     RESERVED_GENERAL_ATTENTION_BIT_9
#define XSTORM_FATAL_ASSERT_ATTENTION_BIT     RESERVED_GENERAL_ATTENTION_BIT_10

/* mcp error attention bit */
#define MCP_FATAL_ASSERT_ATTENTION_BIT        RESERVED_GENERAL_ATTENTION_BIT_11

/*E1H NIG status sync attention mapped to group 4-7*/
#define LINK_SYNC_ATTENTION_BIT_FUNC_0      RESERVED_GENERAL_ATTENTION_BIT_12
#define LINK_SYNC_ATTENTION_BIT_FUNC_1      RESERVED_GENERAL_ATTENTION_BIT_13
#define LINK_SYNC_ATTENTION_BIT_FUNC_2      RESERVED_GENERAL_ATTENTION_BIT_14
#define LINK_SYNC_ATTENTION_BIT_FUNC_3      RESERVED_GENERAL_ATTENTION_BIT_15
#define LINK_SYNC_ATTENTION_BIT_FUNC_4      RESERVED_GENERAL_ATTENTION_BIT_16
#define LINK_SYNC_ATTENTION_BIT_FUNC_5      RESERVED_GENERAL_ATTENTION_BIT_17
#define LINK_SYNC_ATTENTION_BIT_FUNC_6      RESERVED_GENERAL_ATTENTION_BIT_18
#define LINK_SYNC_ATTENTION_BIT_FUNC_7      RESERVED_GENERAL_ATTENTION_BIT_19

/* Used For Error Recovery: changing this will require more changes in code that assume
 * error recovery uses general attn bit20 ! */
#define ERROR_RECOVERY_ATTENTION_BIT		RESERVED_GENERAL_ATTENTION_BIT_20
#define RESERVED_ATTENTION_BIT				RESERVED_GENERAL_ATTENTION_BIT_21

#define LATCHED_ATTN_RBCR               	23
#define LATCHED_ATTN_RBCT               	24
#define LATCHED_ATTN_RBCN               	25
#define LATCHED_ATTN_RBCU               	26
#define LATCHED_ATTN_RBCP               	27
#define LATCHED_ATTN_TIMEOUT_GRC        	28
#define LATCHED_ATTN_RSVD_GRC           	29
#define LATCHED_ATTN_ROM_PARITY_MCP     	30
#define LATCHED_ATTN_UM_RX_PARITY_MCP   	31
#define LATCHED_ATTN_UM_TX_PARITY_MCP   	32
#define LATCHED_ATTN_SCPAD_PARITY_MCP  		33

#define GENERAL_ATTEN_WORD(atten_name)         ((94 + atten_name) / 32)
#define GENERAL_ATTEN_OFFSET(atten_name)       (1UL << ((94 + atten_name) % 32))