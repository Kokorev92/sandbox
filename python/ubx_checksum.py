packet = [0xB5,0x62, 0x06, 0x01, 0x03, 0xF1, 0x00, 0x01]

CK_A,CK_B = 0, 0
for i in range(len(packet)):
  CK_A = CK_A + packet[i]
  CK_B = CK_B + CK_A

# ensure unsigned byte range
CK_A = CK_A & 0xFF
CK_B = CK_B & 0xFF

print("UBX packet checksum:", ("0x%02X,0x%02X" % (CK_A,CK_B)))
