// define default functions
	.macro default_func num:req
	.text
	        .globl default_func\num
	.align 2
	.type default_func\num,@function
	default_func\num:
	.align 3
	.quad .L.default_func\num
	.quad .TOC.@tocbase
	.text
	.L.default_func\num:
	blr
	.long 0
	.quad 0
	.endm

	default_func 0
	default_func 1
	default_func 2
	default_func 3
	default_func 4
	default_func 5
	default_func 6
	default_func 7
	default_func 8
	default_func 9

	default_func 10
	default_func 11
	default_func 12
	default_func 13
	default_func 14
	default_func 15
	default_func 16
	default_func 17
	default_func 18
	default_func 19

	default_func 20
	default_func 21
	default_func 22
	default_func 23
	default_func 24
	default_func 25
	default_func 26
	default_func 27
	default_func 28
	default_func 29

	default_func 30
	default_func 31
	default_func 32
	default_func 33
	default_func 34
	default_func 35
	default_func 36
	default_func 37
	default_func 38
	default_func 39

	default_func 40
	default_func 41
	default_func 42
	default_func 43
	default_func 44
	default_func 45
	default_func 46
	default_func 47
	default_func 48
	default_func 49

	default_func 50
	default_func 51
	default_func 52
	default_func 53
	default_func 54
	default_func 55
	default_func 56
	default_func 57
	default_func 58
	default_func 59

	default_func 60
	default_func 61
	default_func 62
	default_func 63
	default_func 64
	default_func 65
	default_func 66
	default_func 67
	default_func 68
	default_func 69

	default_func 70
	default_func 71
	default_func 72
	default_func 73
	default_func 74
	default_func 75
	default_func 76
	default_func 77
	default_func 78
	default_func 79

	default_func 80
	default_func 81
	default_func 82
	default_func 83
	default_func 84
	default_func 85
	default_func 86
	default_func 87
	default_func 88
	default_func 89

	default_func 90
	default_func 91
	default_func 92
	default_func 93
	default_func 94
	default_func 95
	default_func 96
	default_func 97
	default_func 98
	default_func 99

	default_func 100
	default_func 101
	default_func 102
	default_func 103
	default_func 104
	default_func 105
	default_func 106
	default_func 107
	default_func 108
	default_func 109

	default_func 110
	default_func 111
	default_func 112
	default_func 113
	default_func 114
	default_func 115
	default_func 116
	default_func 117
	default_func 118
	default_func 119

	default_func 120
	default_func 121
	default_func 122
	default_func 123
	default_func 124
	default_func 125
	default_func 126
	default_func 127
	default_func 128
	default_func 129

	default_func 130
	default_func 131
	default_func 132
	default_func 133
	default_func 134
	default_func 135
	default_func 136
	default_func 137
	default_func 138
	default_func 139

	default_func 140
	default_func 141
	default_func 142
	default_func 143
	default_func 144
	default_func 145
	default_func 146
	default_func 147
	default_func 148
	default_func 149

	default_func 150
	default_func 151
	default_func 152
	default_func 153
	default_func 154
	default_func 155
	default_func 156
	default_func 157
	default_func 158
	default_func 159

	default_func 160
	default_func 161
	default_func 162
	default_func 163
	default_func 164
	default_func 165
	default_func 166
	default_func 167
	default_func 168
	default_func 169

	default_func 170
	default_func 171
	default_func 172
	default_func 173
	default_func 174
	default_func 175
	default_func 176
	default_func 177
	default_func 178
	default_func 179

	default_func 180
	default_func 181
	default_func 182
	default_func 183
	default_func 184
	default_func 185
	default_func 186
	default_func 187
	default_func 188
	default_func 189

	default_func 190
	default_func 191
	default_func 192
	default_func 193
	default_func 194
	default_func 195
	default_func 196
	default_func 197
	default_func 198
	default_func 199

	default_func 200
	default_func 201
	default_func 202
	default_func 203
	default_func 204
	default_func 205
	default_func 206
	default_func 207
	default_func 208
	default_func 209

	default_func 210
	default_func 211
	default_func 212
	default_func 213
	default_func 214
	default_func 215
	default_func 216
	default_func 217
	default_func 218
	default_func 219

	default_func 220
	default_func 221
	default_func 222
	default_func 223
	default_func 224
	default_func 225
	default_func 226
	default_func 227
	default_func 228
	default_func 229

	default_func 230
	default_func 231
	default_func 232
	default_func 233
	default_func 234
	default_func 235
	default_func 236
	default_func 237
	default_func 238
	default_func 239

	default_func 240
	default_func 241
	default_func 242
	default_func 243
	default_func 244
	default_func 245
	default_func 246
	default_func 247
	default_func 248
	default_func 249

	default_func 250
	default_func 251
	default_func 252
	default_func 253
	default_func 254
	default_func 255
	