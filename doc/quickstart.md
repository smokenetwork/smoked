Quickstart
----------

### Get current smoked
see [building](building.md) from source if you like to build from source

Pre-build binaries for Ubuntu 16.04 are provided:
- [smoked - for testnet1](https://testnet.smoke.io/downloads/smoked)
- [cli_wallet - for testnet1](https://testnet.smoke.io/downloads/cli_wallet)


### Run smoked

```
./smoked
```

**Note when running the 1st time:**

- For testnet1, copy config from [testnet1.config.ini](../contrib/testnet1.config.ini)

- start smoked a couple of time (stop with `Ctrl+C`) until file `p2p/node_config.json` created.
Copy the private_key in `node_config.json` ( eg., `c1ded8d7deba7c036f18a364b720bcd1fd7575c1530991ddacd2bc105a6be02b` )
and replace to the private-key of p2p-parameters in the `config.ini` file (`0000000000000000000000000000000000000000000000000000000000000000`)

- Remove comment char (`#`) at the beginning of `#p2p-parameters =`

- Then restart smoked, you should see blocks synching

### Configure for your use case
#### Full API node
You need to use `USE_WAY_TOO_MUCH_RAM=1` and `USE_FULL_WEB_NODE=1` as stated above.
You can Use `contrib/fullnode.config.ini` as a base for your `config.ini` file.

#### Exchanges
Use low memory node.

Also make sure that your `config.ini` contains:
```
enable-plugin = account_history
public-api = database_api login_api
track-account-range = ["yourexchangeid", "yourexchangeid"]
```
Do not add other APIs or plugins unless you know what you are doing.


### Resources usage

Please make sure that you have enough resources available.
Check `shared-file-size =` in your `config.ini` to reflect your needs.
Set it to at least 25% more than current size.

For testnet node, 4GB RAM is enought for most use cases.

Provided values are expected to grow significantly over time.

Blockchain data takes over few GB of storage space and growing. 

* Full node:
Shared memory file for full node uses over **4GB**

* Exchange node: Shared memory file for exchange node users over **4GB**
(tracked history for single account)

* Seed node:
Shared memory file for seed node uses over **1GB**

* Other use cases:
Shared memory file size varies, depends on your specific configuration but it is expected to be somewhere between "seed node" and "full node" usage.
