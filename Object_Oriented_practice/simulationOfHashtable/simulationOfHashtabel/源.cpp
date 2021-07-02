#include <iostream>
#include <vector>
using namespace std;


/*
newHt????
���أ��غɣ����ӣ�
_size * 10 / _ht.capacity() >= 7
�������������ݵ�ԭ��
*/

/*
���ñ�ɢ�д����ϣ��ͻʱ�������������ɾ����ϣ�������е�Ԫ�أ���ֱ��ɾ��Ԫ�ػ�Ӱ������Ԫ�ص�������
����ɾ��Ԫ��4�����ֱ��ɾ������44�����������ܻ���Ӱ�졣�������̽����ñ�ǵ�αɾ������ɾ��һ��Ԫ�ء�
//��ϣ��ÿ���ռ�������
//EMPTY��λ�ÿգ�EXIST��λ���Ѿ���Ԫ�أ�DELETEԪ���Ѿ�ɾ��
enum State{EMPTY��EXIST��DELETE}��I
*/


//hash���ʱҪ�������ٳ�ͻ����������һ�Թ�Լ������ͻ���ʱ��ǣ����capacityҪ��������������
static const int num_primes = 32;
static const unsigned long prime_list[num_primes] =
{
	3, 7, 13, 19,
  53,         97,           193,         389,       769,
  1543,       3079,         6151,        12289,     24593,
  49157,      98317,        196613,      393241,    786433,
  1572869,    3145739,      6291469,     12582917,  25165843,
  50331653,   100663319,    201326611,   402653189, 805306457,
  1610612741, 3221225473ul, 4294967291ul
};

unsigned long GetNextPrime(size_t num) {
	for (int i = 0; i < num_primes; ++i) {
		if (prime_list[i] > num)
			return prime_list[i];
	}
	return prime_list[num_primes - 1];
}

enum State { EMPTY, EXIST, DELETE };
template<class key, class value>  //key-value
class hashTable
{
	struct elemt {
		pair<key, value> _val;
		State _state;
	};
public:
//ÿ���ռ䶼Ҫ��key-value, state
//���캯��
	hashTable(size_t capacity = 3):_size(0), _ht(capacity) {
		//_ht(capacity) ��ʼ���б��У���number����Ϊ����������number��С�Ŀռ�	
		for (size_t i = 0; i < capacity; ++i) 
			_ht[i]._state = EMPTY;
	}
public:
//���뷽��
//��ɢ�У�����̽�ⷨ
	bool insert(const pair<key, value>& val)
	{
		// ����ϣ��ײ�ռ��Ƿ����, ��̬�滮��˼��
		checkCapacity();
		size_t hashAddr = hashFunc(val.first);
		// size_t startAddr = hashAddr;
		while (_ht[hashAddr]._state != EMPTY)
		{
			if (_ht[hashAddr]._state == EXIST && _ht[hashAddr]._val.first == val.first)
				return false;   //�ظ���ֵ��Ԫ�����޷������
			hashAddr++;
			if (hashAddr == _ht.capacity())
				hashAddr = 0;
			/*
			// תһȦҲû���ҵ���ע�⣺��̬��ϣ������������Բ��ÿ��ǣ���ϣ����Ԫ�ظ�������
			һ������������ϣ��ͻ���ʻ�������Ҫ���������͹�ϣ��ͻ����˹�ϣ����Ԫ���ǲ��������
			if(hashAddr == startAddr)
			return false;
			*/
		}
		// ����Ԫ��
		_ht[hashAddr]._state = EXIST;
		_ht[hashAddr]._val = val;
		_size++;
		return true;
	}
//��ȡ����
	size_t capacity() {
		return this->_ht.size();
	}
//��ȡsize
	size_t size() {
		return this->_size;
	}
//����
	int find(const key& t) {
		size_t hashAddr = hashFunc(t);
		while (_ht[hashAddr]._state != EMPTY) {
			if (_ht[hashAddr]._state != DELETE && _ht[hashAddr]._val.first == t)
				return hashAddr;
			hashAddr++;
		}
		return -1;
	}
//ɾ��
	bool erase(const key &key) {
		int index = find(key);
		if (-1 == index)
			return false;
		_ht[index]._state = DELETE;
		_size--;
		return true; 
	}
//����hash
	void Swap(hashTable<key, value> &ht) {
		swap(_ht, ht._ht);
		swap(_size, ht._size);
}
private:
//��������� ����������
	void checkCapacity()
	{
		if (_size * 10 / _ht.capacity() >= 7)
		{
			hashTable<key, value> newHt(GetNextPrime(_ht.capacity()));
			for (size_t i = 0; i < _ht.capacity(); ++i){
				if (_ht[i]._state == EXIST)
					newHt.insert(_ht[i]._val);
			}
			Swap(newHt);
		}
	}
//��ϣ������Ѱ�Ҳ����ַ
	size_t hashFunc(const key& data)	{
		return data % _ht.capacity();
	}
private:
	vector<elemt>  _ht;
	size_t       _size;
};
int main() {
	hashTable<int, int> ht;
	int ar[] = { 4, 6, 8, 3, 6, 13, 1, 2, 9 };
	int n = sizeof(ar) / sizeof(int);
	for (int i = 0; i < n; ++i) {
		ht.insert(pair<int, int>(ar[i], ar[i]));
	}
	cout << ht.size() << endl;  //��ǰԪ�ظ���
	ht.erase(8);
	cout << ht.size() << endl;  //ɾ��֮��Ԫ�ظ���
	cout <<"capacity : "<< ht.capacity() << endl;
	cout <<"key = 6 : index = "<< ht.find(6) << endl;
	cout << "key = 8 : index = " << ht.find(8) << endl;
	cout <<"key = 13 : index = " << ht.find(13) << endl;

	return 0;
}

/*
unorderedϵ�й���ʽ�����ĵײ�ʵ����hashtable��
������undered_set��value����key������unordered_map��value�����ֵ�Ե�ֵ
��ϣ����ʹ�ó��������������ŵ�ַ����ôkey�ͱ��������λ���ת��Ϊ���β���ȡģ==
*/