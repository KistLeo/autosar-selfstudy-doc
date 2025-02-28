#ifndef RTE_MEMMAP_H
#define RTE_MEMMAP_H

/* Define the memory sections for the AUTOSAR code */
#if defined(RTE_CODE_EcucPartition_0)
    #define RTE_START_SEC_CODE_EcucPartition_0   __attribute__((section(".RTE_CODE_EcucPartition_0")))
    #define RTE_STOP_SEC_CODE_EcucPartition_0    __attribute__((section(".RTE_STOP_EcucPartition_0")))

#elif defined(RTE_BSW)
    #define RTE_START_SEC_CODE_BSW               __attribute__((section(".RTE_CODE_BSW")))
    #define RTE_STOP_SEC_CODE_BSW                __attribute__((section(".RTE_STOP_BSW")))

#else
    #define RTE_START_SEC_CODE                   __attribute__((section(".RTE_CODE")))
    #define RTE_STOP_SEC_CODE                    __attribute__((section(".RTE_STOP")))
#endif

/* Define the data sections if needed */
#define RTE_START_SEC_DATA                      __attribute__((section(".RTE_DATA")))
#define RTE_STOP_SEC_DATA                       __attribute__((section(".RTE_STOP_DATA")))

#endif /* RTE_MEMMAP_H */
