    .section .text
    .global main

main:
    ########################################################################
    # Test CSRRW: swap x5 with mstatus
    ########################################################################

    # Load a test value
    li   x5, 0x12345678

    # CSRRW x6, mstatus, x5
    # x6 = old mstatus
    # mstatus = x5
    csrrw x6, mstatus, x5

    # After this:
    #   x6 = old mstatus value
    #   mstatus = 0x12345678  (the value we wrote)

    ########################################################################
    # End of main()
    ########################################################################
    ret
