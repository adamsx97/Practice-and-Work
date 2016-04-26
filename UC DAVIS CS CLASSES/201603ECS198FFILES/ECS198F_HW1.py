import rsa
from rsa import key
def main():
    (pub_key, priv_key) = key.newkeys(1024)
    raw = b'I, Chengeng Xiao, signed this sentence!'
    crypto = rsa.encrypt(raw, pub_key)
    signature = rsa.sign(raw, priv_key, 'SHA-256')
    msg = rsa.decrypt(crypto, priv_key)
    #print(rsa.verify(raw, signature, pub_key))

#signature is the same in both - this is the signed version. Your message didn't change - fake == raw
    return msg, signature, pub_key

msg, digsig, pkey = main()

fake = b'I, Chengeng Xiao, signed this sentence'
print(rsa.verify(fake, digsig, pkey))