section .text
global idt_flush

;First we take the adress of the idt table
;then we load it with lidt
idt_flush:
	mov eax, [esp + 4]
	lidt [eax]
	ret
